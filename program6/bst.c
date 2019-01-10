#include <stdio.h>



#include <stdlib.h>



#include "bst.h"







int i = 0;



int x = 0;



int c1 = 0;



int c2 = 0;







int array[50];



int array3[50];



int array2[50];











void deleteTree (Tree * bst);



void shortCircuit(Node * n);



void deleteLeaf(Node * leaf);



void promotion(Node * n);



Data * insert (Tree * bst, Data value);



void sort (Tree * bst, Data * d);



Data * search (Tree * bst, Data value);



Tree * clone(Tree* bst);



int * compare(Tree * t, Tree * copy);



void *removeData (Tree * bst, Data value);







Tree * newTree(){ //complete

	    

	    Tree * t = malloc(sizeof(Tree));

	        

	        t->root = NULL;

		    

		    t->insert = insert;

		        

		        t->search = &search;

			    

			    t->sort = &sort;

			        

			        t->compare = &compare;

				    

				    t->clone = &clone;

				        

				        t->removeData = &removeData;

					    

					    t->delete = &deleteTree;

					        

					        return t;

						    

}







Node * newNode(Data data, Node * parent){ //complete

	    

	    Node * n = malloc(sizeof(Node));

	        

	        n->left = n->right=NULL;

		    

		    n->parent = parent;

		        

		        n->data = data;

			    

			    return n;

			        

}







void shortCircuit(Node * n){ //complete

	    

	    if(n->parent->left==n && n->left!=NULL){

		            n->parent->left = n->left;

			            n->left->parent = n->parent;

				        }

	        else if(n->parent->left==n && n->left==NULL){

			        n->parent->left = n->right;

				        n->right->parent = n->parent;

					    }

		    else if(n->parent->left!=n && n->left != NULL){

			            n->parent->right = n->left;

				            n->left->parent = n->parent;

					        }

		        else if(n->parent->left!=n && n->left == NULL){

				        n->parent->right = n->right;

					        n->right->parent = n->parent;

						    }

			    free(n);

			        

}







void deleteLeaf(Node * n){ //complete

	    

	    if(n->parent == NULL){

		            free(n);

			            return;

				        }

	        else if(n->parent->left == n){

			        n->parent->left = NULL;

				    }

		    else if(n->parent->right == n){

			            n->parent->right = NULL;

				        }

		        free(n);

			    

}







Node * findMinRight(Node * n){ //complete

	    

	    n = n->right;

	        

	        while(n->left!=NULL){

			        

			        n = n->left;

				        

				    }

		    

		    return n;

		        

}







void promotion(Node * n){ //complete

	    

	    Node * minRight = findMinRight(n);

	        

	        n->data = minRight->data;

		    

		    if((minRight->left == NULL) && (minRight->right == NULL)) {

			            

			            deleteLeaf(minRight);

				            

				        }

		        

		        else {

				        

				        shortCircuit(minRight);

					        

					    }

			    

}







Data * searchNode(Node * n, Data d){ //complete

	    

	    if(d.value < n->data.value){

		            if(n->left==NULL) return NULL;

			            else searchNode(n->left, d);

				        }

	        else if(d.value > n->data.value){

			        if(n->right==NULL) return NULL;

				        else searchNode(n->right, d);

					    }

		    else if(d.value == n->data.value){

			            return &(n->data);

				        }

		        

}







Data * insertNode(Node * n, Data d){ //complete

	    

	    if(d.value == n->data.value){

		            return NULL;

			        }

	        else if(d.value < n->data.value){

			        if(n->left != NULL)

					            insertNode(n->left, d);

				        else if(n->left == NULL){

						            n->left = newNode(d,n);

							                return &d;

									        }

					    }

		    else if(d.value > n->data.value){

			            if(n->right != NULL)

					                insertNode(n->right, d);

				            else if(n->right == NULL){

						                n->right = newNode(d,n);

								            return &d;

									            }

					        }

		        

}







Data * insert (Tree * bst, Data value){ //complete

	    

	    if(bst->root == NULL){

		            Tree * x = newTree();

			            bst->root = x;

				            bst->root->data = value;

					            bst->root->left = bst->root->right = NULL;

						            insertNode(bst->root,value);

							        }

	        else{

			        insertNode(bst->root,value);

				    }

}



Data * search (Tree * bst, Data value){ //complete

	    if(bst->root == NULL){

		            return NULL;

			        }

	        else{

			        searchNode(bst->root,value);

				    }

}







void *removeData (Tree * bst, Data value){

	    

	    if(bst->root == NULL){

		            

		            return;

			            

			        }

	        

	        

	        Node* to_delete = searchNode(bst->root,value);

		    

		    if (to_delete != NULL)

			        {

					        if(to_delete->left == NULL && to_delete->right == NULL)

							        {

									            if(to_delete == bst->root){

											                    bst->root=NULL;

													                    free(to_delete);

															                    return;

																	                }

										                else deleteLeaf(to_delete);

												            

												        }

						        

						        

						        

						        

						        else if(to_delete->left == NULL && to_delete->right != NULL)

								        {

										            if (to_delete->data.value == bst->root->data.value)

												                {

															                

															                    

															                    bst->root = to_delete->right;

																	                        free(to_delete);

																				            }

											                else

														            {

																                    shortCircuit(to_delete);

																		                }

													        }

							        

							        

							        

							        

							        else if(to_delete->left != NULL && to_delete->right == NULL)

									        {

											            if (to_delete->data.value == bst->root->data.value)

													                {

																                

																                    

																                    bst->root = to_delete->left;

																		                        free(to_delete);

																					                }

												                

												                else

															            {

																	                    shortCircuit(to_delete);

																			                }

														        }

								        

								        

								        

								        

								        else

										        {

												            promotion(to_delete);

													            }

									    }

		        

}







Data * cloneTree(Node* n){

	    

	    if (n != NULL){

		            

		            array[x] = n->data.value;

			            

			            x++;

				            

				            cloneTree(n->left);

					            

					            cloneTree(n->right);

						            

						        }

	        

}







Tree * clone(Tree* bst){

	    

	    cloneTree(bst->root);

	        

	        int i;

		    

		    Tree *copy_bst = newTree();

		        

		        for (i = 0; i < x; i++){

				        

				        insert(copy_bst, (Data){array[i]});

					        

					    }

			    

			    return copy_bst;

			        

}







void traverse(Node * n, Data * d){ //preorder traversal

	    

	    if(n!=NULL){

		            

		            traverse(n->left,d);

			            

			            d[i] = n->data;

				            

				            i++;

					            

					            traverse(n->right,d);

						            

						        }

	        

}







void sort (Tree * bst, Data * d){

	    

	    traverse(bst->root,d);

	        

}







Data * tree1(Node* n){

	    

	    if (n != NULL){

		            

		            array3[c1] = n->data.value;

			            

			            c1++;

				            

				            tree1(n->left);

					            

					            tree1(n->right);

						            

						        }

	        

}







Data * tree2(Node* n){

	    

	    if (n != NULL){

		            

		            array2[c2] = n->data.value;

			            

			            c2++;

				            

				            tree2(n->left);

					            

					            tree2(n->right);

						            

						        }

	        

}







int * compare(Tree * t, Tree * copy){

	    

	    if (t == NULL)

		            

		            return 0;

	        

	        if(copy == NULL){

			        

			        return 0;

				        

				    }

		    

		    c1 = c2 = 0;

		        

		        tree1(t->root);

			    

			    tree2(copy->root);

			        

			        int i;

				    

				    for (i = 0; i < c1; i++)

					            

					        {

							        

							        if (array2[i] != array3[i]){

									            

									            return 0;

										                

										            }

								        

								    }

				        

				        return 1;

					    

}







void deletePost(Tree *bst, Node*n){

	    

	    if(n != NULL){

		            

		            deletePost(bst, n->left);

			            

			            deletePost(bst,n->right);

				            

				            if(n->parent != NULL){

						                

						                deleteLeaf(n);

								            

								        }

					            

					        }

	        

}







void deleteTree(Tree * bst){

	    

	    deletePost(bst,bst->root);

	        

	        free(bst);

		    

}
